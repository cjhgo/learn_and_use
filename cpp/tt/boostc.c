
namespace ctx = boost::context;

ctx::fcontext_t fcm, * fc1, * fc2;

void f1( intptr_t)
{
        std::cout << "f1: entered" << std::endl;
        std::cout << "f1: call jump_fcontext( fc1, fc2, 0)" << std::endl;
        ctx::jump_fcontext( fc1, fc2, 0);
        std::cout << "f1: return" << std::endl;
        ctx::jump_fcontext( fc1, & fcm, 0);
}

void f2( intptr_t)
{
        std::cout << "f2: entered" << std::endl;
        std::cout << "f2: call jump_fcontext( fc2, fc1, 0)" << std::endl;
        ctx::jump_fcontext( fc2, fc1, 0);
        BOOST_ASSERT( false && ! "f2: never returns");
}

int main( int argc, char * argv[])
{
        ctx::guarded_stack_allocator alloc;
        void * sp1( alloc.allocate(ctx::minimum_stacksize()));
        std::size_t size( ctx::guarded_stack_allocator::minimum_stacksize());

        fc1 = ctx::make_fcontext( sp1, size, f1);
        fc2 = ctx::make_fcontext( sp2, size, f2);

        std::cout << "main: call jump_fcontext( & fcm, fc1, 0)" << std::endl;
        ctx::jump_fcontext( & fcm, fc1, 0);

        std::cout << "main: done" << std::endl;

        return EXIT_SUCCESS;
}