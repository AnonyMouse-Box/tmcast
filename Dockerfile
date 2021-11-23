FROM gcc:latest AS compiler
RUN ["mkdir -p /usr"]
WORKDIR /usr
COPY src .
COPY include .
COPY makefile .
ENTRYPOINT ["make"]

#FROM alpine:latest AS testbed
#COPY --from=0 /usr/build/binary /usr/local/bin/
#CMD ["/usr/local/bin/binary", "test"]
