FROM alpine AS build
RUN apk add --no-cache build-base automake autoconf perl git
RUN git clone https://github.com/annatrembach/DevOps_2.git /src
WORKDIR /src
COPY . .
RUN aclocal
RUN autoconf
RUN automake --add-missing
RUN ./configure
RUN make

FROM alpine
COPY --from=build /src/funcA /usr/local/bin/funcA
ENTRYPOINT ["/usr/local/bin/funcA"]

