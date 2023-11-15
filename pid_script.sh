#!/bin/bash

max_pid=$(cat /proc/sys/kernel/pid_max)
echo "Maximum value of a process ID: $max_pid"
