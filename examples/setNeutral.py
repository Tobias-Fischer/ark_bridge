#!/usr/bin/env python

import rospy
import time
from ark_bridge.msg import Mode, Empty

def response_callback(data):
  global started
  if started:
    rospy.signal_shutdown("Neutral Control Set")

def mode_setter():
  global started
  started = False
  print "Starting..."

  rospy.init_node("neutral_control_setter")
  rospy.Subscriber("/ark_bridge/control_selection_set_mode_response", Empty, response_callback)
  time.sleep(0.3)
  started = True

  print "Setting Neutral Control Mode"

  pub = rospy.Publisher("/ark_bridge/control_selection_set_mode_call", Mode, latch=True, queue_size=1)
  msg = Mode()
  msg.mode = 0
  pub.publish(msg)

  rospy.spin()

  print "Done"

mode_setter()