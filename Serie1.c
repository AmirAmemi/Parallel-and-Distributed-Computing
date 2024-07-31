#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Fonction qui sera exécutée par chaque thread
void* afficher_message(void* arg) {
    int num_thread = *((int*) arg);
    // Récupérer le nombre total de threads créés
    int nb_threads = pthread_active_count_np();
    // Récupérer le nombre d'unités de traitement sur la machine
    int nb_cpus = sysconf(_SC_NPROCESSORS_ONLN);
    // Afficher le message avec les informations supplémentaires
    printf("Bonjour du thread %d sur %d threads et %d unités de traitement.\n", num_thread, nb_threads, nb_cpus);
    return NULL;
}

int main() {
    pthread_t threads[5];
    int args[5];
    // Créer plusieurs threads pour exécuter la fonction afficher_message()
    for (int i = 0; i < 5; i++) {
        args[i] = i;
        pthread_create(&threads[i], NULL, afficher_message, &args[i]);
    }
    // Attendre la fin de tous les threads
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
