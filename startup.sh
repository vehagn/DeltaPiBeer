#!/bin/sh
sleep 1
echo Starting EpsilonPi
/usr/local/EpsilonPi
sleep 1
echo Starting DeltaPi
/usr/local/DeltaPi
echo Shutting down in 10 s. ctrl-c to cancel shutdown.
sleep 10
shutdown -h now