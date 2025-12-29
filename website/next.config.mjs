import nextra from "nextra";

const withNextra = nextra({
    search: true,
    defaultShowCopyCode: true,
});

const isProd = process.env.NODE_ENV === 'production'

/** @type {import('next').NextConfig} */
const nextConfig = {
  output: 'export',
  basePath: isProd ? '/c_traceback' : '',
  assetPrefix: isProd ? '/c_traceback/' : '',
  images: { unoptimized: true }
}

export default withNextra(nextConfig);
