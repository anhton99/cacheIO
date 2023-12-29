#define NUM_THREAD 4

void threadfunc(std::mutex* m, unsigned *x) {
    for (int i = 0; i != 5000000; ++i) {
        m->lock();
        x += 1;
        m->unlock();
    }
}

int main() {
    std::thread  th[NUM_THREAD];
    std::mutex m;
    unsigned n = 0;
    for (int i = 0; i != NUM_THREAD; ++i) {
        th[i] = std::thread(threadfunc, &m, &n);
    }

    for (int i = 0; i != NUM_THREAD; ++i) {
        th[i].join();
    }

    printf("%u\n", n);
    return 0;
}