#include "Medium.h"
#include "BenchIncludes.h"
#include <map>
using namespace std;

static void Mbench_at(State& state)
{
    auto N = state.range(0);
    map <Medium, Medium> m{};
    Medium A[N];
    Medium B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.at(A[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_at)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


static void Mbench_operator(State& state)
{
    auto N = state.range(0);
    map <Medium, Medium> m{};
    Medium A[N];
    Medium B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m[A[0]];
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_operator)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_empty(State& state)
{
    auto N = state.range(0);
    map <Medium, Medium> m{};
    Medium A[N];
    Medium B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.empty();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_empty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_size(State& state)
{
    auto N = state.range(0);
    map <Medium, Medium> m;
    Medium A[N];
    Medium B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_size)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_maxsize(State& state)
{
    auto N = state.range(0);
    map <Medium, Medium> m;
    Medium A[N];
    Medium B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.max_size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_maxsize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_clear(State& state)
{
    auto N = state.range(0);
    map <Medium, Medium> m;
    Medium A[N];
    Medium B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
    }

    for(auto _: state)
    {
        state.PauseTiming();
        for(int i=0; i<N; i++)
        {
            m.insert({A[i],B[i]});
        }
        state.ResumeTiming();

        m.clear();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_clear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_insert(State& state)
{
    auto N = state.range(0);
    map <Medium, Medium> m;
    Medium A {};
    Medium B{};
    A.randomize();
    B.randomize();

    for(auto _: state)
    {
        m.insert({A,B});

        state.PauseTiming();
        m.erase(A);
        state.ResumeTiming();

    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_insert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_erase(State& state)
{
    auto N = state.range(0);
    map <Medium, Medium> m;
    Medium A {};
    Medium B{};
    A.randomize();
    B.randomize();

    for(auto _: state)
    {
        state.PauseTiming();
        m.insert({A,B});
        state.ResumeTiming();

        m.erase(A);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_erase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_swap(State& state)
{
    auto N = state.range(0);
    map <Medium, Medium> m;
    map <Medium, Medium> w;
    Medium A[N];
    Medium B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
        w.insert({B[i], A[i]});
    }

    for(auto _: state)
    {
        m.swap(w);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_swap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_count(State& state)
{
    auto N = state.range(0);
    map <Medium, Medium> m{};
    Medium A[N];
    Medium B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.count(A[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_count)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_find(State& state)
{
    auto N = state.range(0);
    map <Medium, Medium> m{};
    Medium A[N];
    Medium B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.find(A[5]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_find)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_equalrange(State& state)
{
    auto N = state.range(0);
    map <Medium, Medium> m{};
    Medium A[N];
    Medium B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.equal_range(B[5]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_equalrange)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_lowerbound(State& state)
{
    auto N = state.range(0);
    map <Medium, Medium> m{};
    Medium A[N];
    Medium B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.lower_bound(A[5]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_lowerbound)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_upperbound(State& state)
{
    auto N = state.range(0);
    map <Medium, Medium> m{};
    Medium A[N];
    Medium B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.upper_bound(A[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_upperbound)->RangeMultiplier(2)->Range(1, 1024)->Complexity();