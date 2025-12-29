const isProd = process.env.NODE_ENV === 'production';
const prefix = isProd ? '/c_traceback' : '';
export { prefix };