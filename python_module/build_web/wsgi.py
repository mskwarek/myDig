"""
WSGI config for sweetspot.
"""

import os
import sys
import thread

os.environ.setdefault("DJANGO_SETTINGS_MODULE", "settings")

sys.path.append('/home/mkoi/mgr/myDig/python_module/')
sys.path.append('/home/mkoi/mgr/myDig/python_module/build_web')
sys.path.append('/home/mkoi/mgr/myDig/python_module/client')


from django.core.wsgi import get_wsgi_application
from axfrWrapper import *

def process():
    input_list = [line.rstrip('\n').split(' ') for line in open('/home/mkoi/mgr/myDig/python_module/inputData')]
    process_lookup(input_list)

thread.start_new_thread(process, ())
application = get_wsgi_application()
