FROM node:alpine

WORKDIR /usr/app

ARG VERSION="1.0.0"

RUN echo '{ \
  "name": "webapp",  \
  "version": "'"$VERSION"'", \
  "main": "index.js", \
  "scripts": { "start": "node index.js" }, \
  "dependencies": { "express": "^4.18.2" } \
}' > package.json

RUN npm install

COPY index.js .

EXPOSE 8080

CMD ["npm", "start"]
