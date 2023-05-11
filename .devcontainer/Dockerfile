
# Created by Devin Headrick 2023, May 4th
# Referencing this: https://github.com/astroesteban/fprime-devcontainer/blob/main/.devcontainer/Dockerfile
#  and Roberts fprime example zip on slack 
FROM debian:bullseye-slim

# LABEL Name=cubics_fprime_devcontainer Version=0.0.1
LABEL Name=cubics_obc_software_test Version=0.0.1


#Set the dockerfile arg username to fprime-dev and set the $USERNAME env variable in the container to fprime-dev
ARG USERNAME=fprime-dev  
ENV USERNAME=${USERNAME}

#Setup OS environment
RUN apt-get -y update && \
	apt-get upgrade -y && \
	#This creates a user named 'fprime-dev' and adds them to the sudo group, defines the name 
	#  of the users login shell as /bin/bash , and changes the users password to 'fprime'
	useradd -G "sudo" -s "/bin/bash" -m -U ${USERNAME} && echo ${USERNAME}":fprime" | chpasswd && \
	apt-get install --no-install-recommends -y \
	sudo \
	git \
	build-essential \
	docker.io \
	cmake \
	clang-format \
	autoconf \
	automake \
	libtool \
	curl \
	make \
	g++ \
 	unzip \
	wget \
	ca-certificates \
	ssl-cert \
	zlib1g-dev \
	python3 \
	python3-pip \
	#For using fprime tools within a virtual env as recommended in the fprime-community tutorials
	python3-venv  \
	gdb


#BIND-MOUNT THE CONTAINER USERS BASH HISTORY TO A FILE ON THE USERS HOST MACHINE
# Create a directory for the bind-mount and set ownership to the fprime-dev user
RUN mkdir -p /home/$USERNAME/persistent && \
    chown -R $USERNAME /home/$USERNAME/persistent && \
    echo "source /home/$USERNAME/persistent/.bashrc" >> "/home/$USERNAME/.bashrc"

# Add an entry in the .bashrc file to load the persistent .bashrc if it exists
RUN echo 'if [ -f /home/$USERNAME/persistent/.bashrc ]; then source /home/$USERNAME/persistent/.bashrc; fi' >> /home/$USERNAME/.bashrc

# Add an entry in the .bashrc file to store and load the persistent bash history, with timestamps 
RUN echo 'export HISTFILE=/home/$USERNAME/persistent/.bash_history' >> /home/$USERNAME/.bashrc && \
	echo "export HISTTIMEFORMAT='%m/%d/%y %T'" >> /home/$USERNAME/.bashrc && \
    echo 'export PROMPT_COMMAND="history -a; $PROMPT_COMMAND"' >> /home/$USERNAME/.bashrc


#Setup 32bit ARM cross compiling packages in /opt/toolchains dir as per frpime tutorial example:
# https://github.com/fprime-community/fprime-workshop-led-blinker/blob/main/docs/prerequisites.md
RUN mkdir -p /opt/toolchains && \
	chown fprime-dev /opt/toolchains && \
	#Download the provided cross compiling packages for Fprime from ARM
	# Note: Certificates aren't checked rn because it keeps failing (this is not recommended but works...)
	wget --no-check-certificate https://developer.arm.com/-/media/Files/downloads/gnu-a/10.2-2020.11/binrel/gcc-arm-10.2-2020.11-x86_64-arm-none-linux-gnueabihf.tar.xz && \
	#Move file to the /opt/toolchains dir and extract 
	mv gcc-arm-10.2-2020.11-x86_64-arm-none-linux-gnueabihf.tar.xz /opt/toolchains && \
	tar -xvf /opt/toolchains/gcc-arm-10.2-2020.11-x86_64-arm-none-linux-gnueabihf.tar.xz --strip-components=1 -C /opt/toolchains && \
	#Setup build path environment variable. This must be placed in bash otherwise it only exists in a temp shell instance
	echo 'export ARM_TOOLS_PATH=/opt/toolchains/bin' >> /home/$USERNAME/.bashrc


#Install pip setup tools
RUN pip3 install -U setuptools setuptools_scm wheel pip

#Install initial bootstrap version of Fprime tools 
RUN pip3 install fprime-tools

CMD [ "/bin/bash", "-l"]