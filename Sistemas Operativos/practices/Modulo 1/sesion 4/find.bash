#!/bin/bash
find /root -mtime 0 > modificados_$(date +"<"%Y"><"%d"><"%H:%m">")
