############################################################################
# Copyright (C) 2016  Internet Systems Consortium, Inc. ("ISC")
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
############################################################################

import os

# These routines permit platform-independent location of BIND 9 tools
if os.name == 'nt':
    import win32con
    import win32api


def prefix(bindir=''):
    if os.name != 'nt':
        return os.path.join('/usr/local', bindir)

    hklm = win32con.HKEY_LOCAL_MACHINE
    bind_subkey = "Software\\ISC\\BIND"
    sam = win32con.KEY_READ
    h_key = None
    key_found = True
    # can fail if the registry redirected for 32/64 bits
    try:
        h_key = win32api.RegOpenKeyEx(hklm, bind_subkey, 0, sam)
    except:
        key_found = False
    # retry for 32 bit python with 64 bit bind9
    if not key_found:
        key_found = True
        sam64 = sam | win32con.KEY_WOW64_64KEY
        try:
            h_key = win32api.RegOpenKeyEx(hklm, bind_subkey, 0, sam64)
        except:
            key_found = False
    # retry 64 bit python with 32 bit bind9
    if not key_found:
        key_found = True
        sam32 = sam | win32con.KEY_WOW64_32KEY
        try:
            h_key = win32api.RegOpenKeyEx(hklm, bind_subkey, 0, sam32)
        except:
            key_found = False
    if key_found:
        try:
            (named_base, _) = win32api.RegQueryValueEx(h_key, "InstallDir")
        except:
            key_found = False
        win32api.RegCloseKey(h_key)
    if key_found:
        return os.path.join(named_base, bindir)
    return os.path.join(win32api.GetSystemDirectory(), bindir)


def shellquote(s):
    if os.name == 'nt':
        return '"' + s.replace('"', '"\\"') + '"'
    return "'" + s.replace("'", "'\\''") + "'"


version = '9.11.0-P3'
if os.name != 'nt':
    sysconfdir = '/etc'
else:
    sysconfdir = prefix('etc')
