import nextra from "nextra";

import { prefix } from "./prefix.ts";

const withNextra = nextra({
    search: true,
    defaultShowCopyCode: true,
});

/** @type {import('next').NextConfig} */
const nextConfig = {
  output: 'export',
  basePath: prefix,
  assetPrefix: prefix,
  images: { unoptimized: true }
}

export default withNextra(nextConfig);
