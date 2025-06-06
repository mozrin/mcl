#ifndef EXTENSION_SQRT_H
#define EXTENSION_SQRT_H

#include "../../core/common/value.h"
#include "../../core/runtime/evaluator.h"

Value mcl_sqrt(const std::vector<Value> &args);

void register_sqrt_extension(Evaluator &eval);

#endif