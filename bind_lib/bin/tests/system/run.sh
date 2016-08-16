#!/bin/sh
#
# Copyright (C) 2000, 2001, 2004, 2007, 2010, 2012, 2014-2016  Internet Systems Consortium, Inc. ("ISC")
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

#
# Run a system test.
#

SYSTEMTESTTOP=.
. $SYSTEMTESTTOP/conf.sh

stopservers=true
clean=true

case $1 in
   --keep|-k) stopservers=false; shift ;;
   --noclean|-n) clean=false; shift ;;
esac

test $# -gt 0 || { echo "usage: $0 [--keep|--noclean] test-directory" >&2; exit 1; }

test=$1
shift

test -d $test || { echo "$0: $test: no such test" >&2; exit 1; }

echo "S:$test:`date`" >&2
echo "T:$test:1:A" >&2
echo "A:System test $test" >&2

if [ x${PERL:+set} = x ]
then
    echo "I:Perl not available.  Skipping test." >&2
    echo "R:UNTESTED" >&2
    echo "E:$test:`date`" >&2
    exit 0;
fi

$PERL testsock.pl || {
    echo "I:Network interface aliases not set up.  Skipping test." >&2;
    echo "R:UNTESTED" >&2;
    echo "E:$test:`date`" >&2;
    exit 0;
}


# Check for test-specific prerequisites.
test ! -f $test/prereq.sh || ( cd $test && $SHELL prereq.sh "$@" )
result=$?

if [ $result -eq 0 ]; then
    : prereqs ok
else
    echo "I:Prerequisites for $test missing, skipping test." >&2
    [ $result -eq 255 ] && echo "R:SKIPPED" || echo "R:UNTESTED"
    echo "E:$test:`date`" >&2
    exit 0
fi

# Check for PKCS#11 support
if
    test ! -f $test/usepkcs11 || $SHELL cleanpkcs11.sh
then
    : pkcs11 ok
else
    echo "I:Need PKCS#11 for $test, skipping test." >&2
    echo "R:PKCS11ONLY" >&2
    echo "E:$test:`date`" >&2
    exit 0
fi

# Set up any dynamically generated test data
if test -f $test/setup.sh
then
   ( cd $test && $SHELL setup.sh "$@" )
fi

# Start name servers running
$PERL start.pl $test || { echo "E:$test:`date`"; exit 1; }

# Run the tests
( cd $test ; $SHELL tests.sh )

status=$?

if $stopservers
then
    :
else
    exit $status
fi

# Shutdown
$PERL stop.pl $test

status=`expr $status + $?`

if [ $status != 0 ]; then
	echo "R:FAIL"
	# Don't clean up - we need the evidence.
	find . -name core -exec chmod 0644 '{}' \;
else
	echo "R:PASS"

	if $clean
	then
		rm -f $SYSTEMTESTTOP/random.data
		if test -f $test/clean.sh
		then
			( cd $test && $SHELL clean.sh "$@" )
		fi
		if test -d ../../../.git
		then
			git status -su $test |
			sed -n 's/^?? \(.*\)/I:file \1 not removed/p'
		fi

	fi
fi

echo "E:$test:`date`"

exit $status
