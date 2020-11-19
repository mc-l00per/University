#!/bin/bash
name_file=$(date +%Y-%j-%T)
ps -ef > /root/HDD/$name_file
echo Mi pid = $$ >> /root/HDD/$name_file
