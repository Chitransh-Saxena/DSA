/*
    If we have two functions, which are using 2 mutexes (same mutex variables), but in different order
    -> So, one thread will access one function and mu1 will lock mu2
    -> Second thread will access second function, mu2 will lock mu1
    -> Thus, they both end up waiting to be freed by each other

    -> To avoid deadlocks, we have to make sure that the mutexes are used in same order
        -> Instead of making sure that we are locking in the same order, we can also do something even more organized
        -> ORIGINALLY :
            -> std::lock_guard<std::mutex> locker_1(mu_1);
            -> std::lock_guard<std::mutex> locker_2(mu_2);
        -> New and improvised approach
            -> std::lock(mu_1, mu_2);                                           // This will lock the mutexes
            -> std::lock_guard<std::mutex> locker_1(mu_1, std::adopt_lock());   // std::adopt_lock() will tell that the mutexes are already locked
            -> // std::adopt_lock() will also tell that all the locker needs to do is to adopt to the ownership of the lock, so that when you go out of scope
                ->  the mutex is unlocked
    
    What could be the situations where the deadlock could be introduced?
        -> Prefer locking single mutex. (Do not lock 2 mutexes at once unless absolutely necessary, if so, use std::lock)
        -> Avoid locking a mutex and call a user defined function, because we don't know what a user defined function will do
        -> Lock the mutexes in same order
*/