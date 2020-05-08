import java.util.concurrent.*;

public class TPExample
{
	public static void main(String[] args) {
	int numTasks = Integer.parseInt(args[0].trim());

	// Create the thread pool
	ExecutorService pool = Executors.newCachedThreadPool();
	// Run each task using a thread in the pool
	for (int i = 0; i < numTasks; i++)
		pool.execute(new Task());
		// Shut down the pool. This shuts down the pool only
		// after all threads have completed.
		pool.shutdown();
	}
}
