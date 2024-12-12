FROM alpine
WORKDIR /home/trembach/Downloads/DevOpsLabs/DevOps_2/funcAimages
COPY ./funcA .
RUN apk add libstdc++
RUN apk add libc6-compat
ENTRYPOINT ["./funcA"]
