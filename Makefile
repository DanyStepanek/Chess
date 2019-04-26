NAME=chess
# Default IP address uses internal-ip npm cli package
# install by: npm i -g internal-ip-cli
IP ?= $(internal-ip --ipv4)

$(NAME):
	make run -C ./src

run:
	make run -C ./src

clean:
	make clean -C ./src

docker-build:
	docker build -t icpchess .

docker-run-macos:
	docker run -e DISPLAY=$(IP):0 --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -it -v /tmp/.X11-unix:/tmp/.X11-unix:rw -v "$(shell pwd)/src:/ICP" -w /ICP icpchess

docker-run:
	docker run --net=host -e DISPLAY=$($DISPLAY) -v $($HOME)/.Xauthority:/root/.Xauthority:rw --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -it -v "$(shell pwd)/src:/ICP" -w /ICP icpchess

docker-stop:
	docker rm `docker ps --no-trunc -aq`

# Runs socat to network bridge X Window to XQuartz on MacOS
socat-macos:
	socat TCP-LISTEN:6000,reuseaddr,fork UNIX-CLIENT:\"$DISPLAY\"
