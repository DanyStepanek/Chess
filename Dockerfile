FROM centos:7.6.1810
RUN yum -y update && yum install -y gcc gcc-c++ make valgrind gdb qt5-qtbase-devel
