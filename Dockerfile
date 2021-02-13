# GCC support can be specified at major, minor, or micro version
# (e.g. 8, 8.2 or 8.2.0).
# See https://hub.docker.com/r/library/gcc/ for all supported GCC
# tags from Docker Hub.
# See https://docs.docker.com/samples/library/gcc/ for more on how to use this image
FROM gcc:latest

RUN apt-get update && \
    apt-get install -y \
      cmake \
      libxmu-dev libxi-dev \
      freeglut3-dev 

# These commands copy your files into the specified directory in the image
# and set that as the working location
COPY . /usr/src/virtual-scene/
WORKDIR /usr/src/virtual-scene

# This command compiles your app using GCC, adjust for your source code
RUN cmake CMakeLists.txt && make

ENTRYPOINT ["./virtual-scene"]

