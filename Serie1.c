#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Fonction qui sera ex�cut�e par chaque thread
void* afficher_message(void* arg) {
    int num_thread = *((int*) arg);
    // R�cup�rer le nombre total de threads cr��s
    int nb_threads = pthread_active_count_np();
    // R�cup�rer le nombre d'unit�s de traitement sur la machine
    int nb_cpus = sysconf(_SC_NPROCESSORS_ONLN);
    // Afficher le message avec les informations suppl�mentaires
    printf("Bonjour du thread %d sur %d threads et %d unit�s de traitement.\n", num_thread, nb_threads, nb_cpus);
    return NULL;
}

int main() {
    pthread_t threads[5];
    int args[5];
    // Cr�er plusieurs threads pour ex�cuter la fonction afficher_message()
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
