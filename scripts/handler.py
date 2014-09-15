#!/usr/bin/env python

import signal, os

def handler(signum, frame):
    print 'Signal handler called with signal', signum
    print frame	

# Set the signal handler and a 5-second alarm
signal.signal(signal.SIGALRM, handler)
signal.alarm(5)
