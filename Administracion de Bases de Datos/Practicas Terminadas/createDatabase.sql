create database oradbam user sys identified by ABD3oradba
user system identified by ABD3oradba
logfile
group 1 ('/databases/app/oracle/oradata/oradbam/redo01.log') size 10M,
group 2 ('/databases/app/oracle/oradata/oradbam/redo02.log') size 10M,
group 3 ('/databases/app/oracle/oradata/oradbam/redo03.log') size 10M
maxlogfiles 5
maxlogmembers 5
maxloghistory 1
maxdatafiles 100
maxinstances 1
character set us7ascii
national character set al16utf16
datafile '/databases/app/oracle/oradata/oradbam/system01.dbf' size 350M reuse
extent management local
sysaux datafile '/databases/app/oracle/oradata/oradbam/sysaux01.dbf' size 100M reuse 
default temporary tablespace temp
tempfile '/databases/app/oracle/oradata/oradbam/temp01.dbf' size 20M reuse
undo tablespace undotbs1
datafile '/databases/app/oracle/oradata/oradbam/undotbs101.dbf' size 50m reuse autoextend on next 5120k maxsize unlimited;
