#include <asm.h>
#include <parserCore.h>

#include <stmt/for_range.hpp>
parserTypes::stmt::ForRange::ForRange(int begin, int end) {
  this->start = begin;
  this->end = end;
}
parserTypes::stmt::ForRange::~ForRange() {}
void parserTypes::stmt::ForRange::exec(parserCore& ctx) {
  ctx.stream << "# for range\n";
  ctx.Asm->startOfLoop(end - start, start);
  while (ctx.iter.hasData()) {
    if (ctx.iter.peek() == L"}") break;
    ctx.stmt();
  }
  ctx.Asm->endOfLoop();
  ctx.stream << "# for range - end\n";
}