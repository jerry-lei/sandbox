"""
How to use:
- put @debugger before a function created
Example:

!====Another .py====!
from debug import debugger

@debugger
def foo(a,b,c):
    return a,b,c

foo("aadvark", "bear", "claw")
!===================!
"""

import time

def debugger(fxn):
    def testing(*arg):
        t = time.time()
        print "\n!=====Testing function: " + fxn.func_name + "=====!"
        print fxn.func_name + str(arg)
        print "Returns: ",
        print fxn(*arg)
        print 'Execution time: ' + str(time.time() - t) + ' seconds'
        print "!" + ("=" * 23) + ("=" * (len(fxn.func_name) + 5)) + "!\n"
    return testing
