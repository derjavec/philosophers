Philosophers is a concurrency and synchronization project designed to introduce students to multithreading and process synchronization in C. The project is based on the classic Dining Philosophers Problem, a common problem in computer science that illustrates the challenges of resource sharing, deadlocks, and race conditions.
🧠 The Problem

A group of philosophers sits at a round table with one fork between each pair. Philosophers can only perform three actions:

    Thinking 🤔
    Eating 🍝 (which requires picking up both forks)
    Sleeping 😴

Each philosopher needs two forks to eat, but they must share them with their neighbors. The goal is to prevent deadlocks and starvation, ensuring that all philosophers can eat in a fair manner.
✅ Understanding process-based concurrency in C.
✅ Implementing semaphores for synchronization.
✅ Managing process creation, termination, and inter-process communication.
✅ Handling race conditions and deadlock prevention efficiently.
