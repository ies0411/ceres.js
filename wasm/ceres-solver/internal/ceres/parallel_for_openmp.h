// Ceres Solver - A fast non-linear least squares minimizer
// Copyright 2018 Google Inc. All rights reserved.
// http://ceres-solver.org/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
// * Neither the name of Google Inc. nor the names of its contributors may be
//   used to endorse or promote products derived from this software without
//   specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Authors: vitus@google.com (Michael Vitus),
//          dmitriy.korchemkin@gmail.com (Dmitriy Korchemkin)

// This include must come before any #ifndef check on Ceres compile options.
#ifndef CERES_INTERNAL_PARALLEL_FOR_OPENMP_H_
#define CERES_INTERNAL_PARALLEL_FOR_OPENMP_H_

#include "ceres/internal/config.h"

#if defined(CERES_USE_OPENMP)

#include "ceres/parallel_for.h"
#include "ceres/scoped_thread_token.h"
#include "ceres/thread_token_provider.h"
#include "glog/logging.h"
#include "omp.h"

namespace ceres::internal {

template <typename F>
void ParallelInvoke(ContextImpl* context,
                    int start,
                    int end,
                    int num_threads,
                    const F& function) {
  using namespace parallel_for_details;
  ThreadTokenProvider token_provider(num_threads);
#pragma omp parallel num_threads(num_threads)
  {
    const ScopedThreadToken scoped_thread_token(&token_provider);
    const int thread_id = scoped_thread_token.token();
#pragma omp for schedule(guided)
    for (int i = start; i < end; ++i) {
      Invoke<F>(thread_id, i, function);
    }
  }
}

}  // namespace ceres::internal

#endif
#endif
