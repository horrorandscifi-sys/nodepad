const fastify = require('fastify')({ logger: true });
const nativeEngine = require('./build/Release/server_engine');

fastify.get('/compute', async (request, reply) => {
    // Вызываем C++ функцию напрямую
    const stats = nativeEngine.hardWork();
    return { status: 'done', data: stats };
});

fastify.listen({ port: 3000 }, (err) => {
    if (err) throw err;
    console.log('Advanced Server running at http://localhost:3000');
});
