#pragma once
#ifndef CONDUTIL_H
#define CONDUTIL_H

namespace parserTypes
{
    class parserContext;
    class cond;
    class condAnd;
    class condChild;
} // namespace parserTypes

namespace util{
    using namespace parserTypes;
    
    condChild invertConditional(condChild source);
    condAnd invertConditional(cond source);
    cond invertConditional(condAnd source);
}

#endif