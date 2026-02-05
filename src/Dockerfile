# Stage 1: Build C++ and TS
FROM node:18-bullseye AS builder
WORKDIR /app
RUN apt-get update && apt-get install -y build-essential python3
COPY package*.json ./
RUN npm install
COPY . .
RUN npm run build:native
RUN npm run build:ts

# Stage 2: Runtime
FROM node:18-slim
WORKDIR /app
COPY --from=builder /app/build/Release/high_load_engine.node ./build/Release/
COPY --from=builder /app/dist ./dist
COPY --from=builder /app/package*.json ./
RUN npm install --production
EXPOSE 3000
CMD ["node", "dist/index.js"]
