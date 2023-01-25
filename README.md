<!-- <p align="center">
  <a href="https://pcljs.org" target="_blank"><img style="height: 100px" src="./logo.svg" title="pcl.js" alt="title="pcl.js"></a>
  <p align="center"><a href="https://pointclouds.org" target="_blank">Point Cloud Library (PCL)</a> for browser, powered by WebAssembly.</p>
</p> -->
<!--
<p align="center">
  <a href="https://github.com/luoxuhai/pcl.js/actions/workflows/test.yml">
    <img src="https://github.com/luoxuhai/pcl.js/actions/workflows/test.yml/badge.svg" alt="Tests" />
  </a>
  <a href="https://www.npmjs.com/package/pcl.js">
    <img src="https://img.shields.io/npm/v/pcl.js.svg" alt="npm version">
  </a>
 <a href="https://bundlephobia.com/package/pcl.js">
    <img src="https://img.shields.io/bundlephobia/min/pcl.js.svg" alt="Bundle Size">
 </a>
 <a href="https://github.com/FoalTS/foal/blob/master/LICENSE">
    <img src="https://img.shields.io/badge/License-MIT-blue.svg" alt="License: MIT">
  </a>
  <a href="https://www.npmtrends.com/pcl.js">
    <img src="https://img.shields.io/npm/dm/pcl.js" alt="Downloads" />
  </a>
  <a href="https://www.jsdelivr.com/package/npm/pcl.js">
    <img src="https://data.jsdelivr.com/v1/package/npm/pcl.js/badge?style=rounded" alt="jsDelivr" />
  </a>
  <a href="https://openbase.com/js/pcl.js?utm_source=embedded&amp;utm_medium=badge&amp;utm_campaign=rate-badge">
    <img src="https://badges.openbase.com/js/rating/pcl.js.svg?token=nF4Z9XUsUhOe5yeVDZTPwpdoKqqamFbVBoVA5zbU5iM=" alt="Rate this package" />
  </a>
  <a href="https://deepscan.io/dashboard#view=project&tid=18815&pid=22098&bid=649724">
    <img alt="DeepScan" src="https://deepscan.io/api/teams/18815/projects/22098/branches/649724/badge/grade.svg">
  </a>
</p> -->

<!-- <p align="center">
  English | <a href="./README-zh_CN.md"></a>
</p> -->

## Overview

**ceres.js** is a [Ceres-Sovler] (http://ceres-solver.org/) that runs in the browser, powered by [Emscripten](https://emscripten.org) and [WebAssembly](https://webassembly.org)

Ceres Solver is an open source C++ library for modeling and solving large, complicated optimization problems. It can be used to solve Non-linear Least Squares problems with bounds constraints and general unconstrained optimization problems. It is a mature, feature rich, and performant library.


## Demos

<!-- <p>
  <a href="https://kl2zjs.csb.app" title="Removing outliers from point cloud data"><img src="./website/static/img/examples/StatisticalOutlierRemoval.jpg" width="30%" /></a>
  <a href="https://1t72c1.csb.app/" title="Iterative Closest Point algorithm"><img src="./website/static/img/examples/IterativeClosestPoint.jpg" width="30%" /></a>
  <a href="https://o4y07f.csb.app" title="Min-Cut Based Segmentation"><img src="./website/static/img/examples/MinCutSegmentation.jpg" width="30%" /></a>
  <a href="https://3l6tfj.csb.app" title="Extract point cloud keypoints"><img src="./website/static/img/examples/ISSKeypoint3D.jpg" width="30%" /></a>

  <p><a href="https://pcljs.org/examples">See all demos</a></p>
<p> -->

## Features

- :sunglasses: Provides an API similar to Ceres-Solver(C++), easy to use
- :purple_heart: Supports all modern browsers and Node.js 14+
- 💪 Written in TypeScript, with predictable static typing
- 🚀 And many, many more!

## Resources

<!-- - [Documentation](https://pcljs.org/docs/tutorials/intro)
- [API Reference](https://pcljs.org/docs/api/about)
- [Examples](https://pcljs.org/examples)
- [Discussions](https://github.com/luoxuhai/pcl.js/discussions) -->

## Environment Support

| <img src="https://raw.githubusercontent.com/alrra/browser-logos/main/src/edge/edge_128x128.png" alt="Edge" width="48px" height="48px" /><br/> Edge | <img src="https://raw.githubusercontent.com/alrra/browser-logos/main/src/firefox/firefox_128x128.png" alt="Firefox" width="48px" height="48px" /><br/>Firefox | <img src="https://raw.githubusercontent.com/alrra/browser-logos/main/src/chrome/chrome_128x128.png" alt="Chrome" width="48px" height="48px" /><br/>Chrome | <img src="https://raw.githubusercontent.com/alrra/browser-logos/main/src/safari/safari_128x128.png" alt="Safari" width="48px" height="48px" /><br/>Safari | <img src="https://raw.githubusercontent.com/alrra/browser-logos/main/src/opera/opera_128x128.png" alt="Opera" width="48px" height="48px" /><br/>Opera | <img src="https://raw.githubusercontent.com/alrra/browser-logos/main/src/node.js/node.js_128x128.png" alt="Node.js" width="48px" height="48px" /><br/>Node.js |
| --------- | --------- | --------- | --------- | --------- | --------- |
| 16+ | 52+ | 57+ | 11+ | 44+ | 14+

## Bundle Size

> ceres.js version: latest
<!--
| Source        |                                                    Link                                                     |     Size      |
| :------------ | :---------------------------------------------------------------------------------------------------------: | :-----------: |
| pcl.js        |     [https://cdn.jsdelivr.net/npm/pcl.js/dist/pcl.js](https://cdn.jsdelivr.net/npm/pcl.js/dist/pcl.js)      | ~36k gzip’d |
| pcl-core.wasm | [https://cdn.jsdelivr.net/npm/pcl.js/dist/pcl-core.wasm](https://cdn.jsdelivr.net/npm/pcl.js/dist/pcl-core.wasm) | ~553k gzip’d  | -->

## Installation
- emscripten  : 3.1.26 version
<!--
```bash
# NPM
npm install pcl.js

# Yarn
yarn add pcl.js
```
 -->

<!--
```typescript
import * as PCL from 'pcl.js';

async function main() {
  // Initialization
  await PCL.init({
    /**
     * Recommend, optional configuration, custom WebAssembly file link.
     * @default js file dir + pcl-core.wasm
     */
    url: 'https://cdn.jsdelivr.net/npm/pcl.js/dist/pcl-core.wasm',
    // You can also pass an ArrayBuffer of WebAssembly files.
    // arrayBuffer: ArrayBuffer
  });

  // ...
} -->

## Changelog

<!-- The [changelog](https://github.com/luoxuhai/pcl.js/releases) is regularly updated to reflect what's changed in each new release. -->

## Roadmap

<!-- Checkout the full roadmap [here](https://github.com/users/luoxuhai/projects/3). -->

## Online Development

<!-- Use Gitpod, a free online dev environment for GitHub. -->

<!-- [![Open in Gitpod](https://gitpod.io/button/open-in-gitpod.svg)](https://gitpod.io/#https://github.com/luoxuhai/pcl.js) -->

## Contributing

ceres.js has adopted the [Contributor Covenant](https://www.contributor-covenant.org/) as its Code of Conduct, and we expect project participants to adhere to it. Please read [the full text](CODE_OF_CONDUCT.md) so that you can understand what actions will and will not be tolerated.

Please make sure to read the [Contributing Guide](CONTRIBUTING.md) before making a pull request.

Thank you to all the people who already contributed to ceres.js!

![Contributors](https://opencollective.com/ceresjs/contributors.svg?button=false)

## License

<!-- This project is licensed under the terms of the [MIT license](https://github.com/luoxuhai/pcl.js/blob/master/LICENSE). -->

## Star History

<!-- [![Star History Chart](https://api.star-history.com/svg?repos=bytebase/star-history&type=Date)](https://star-history.com/#bytebase/star-history&Date) -->

