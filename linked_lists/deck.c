#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define MAX 50

typedef int Key;

typedef struct Card
{
    Key key;
    struct Card *next;
    struct Card *previous;
} Card;

typedef struct
{
    Card *head;
} Deck;

void startdeck(Deck *deck)
{
    deck->head = (Card *)malloc(sizeof(Card));
    deck->head->next = deck->head;
    deck->head->previous = deck->head;
}

void restartDeck(Deck *deck)
{
    Card *next = deck->head->next;

    while (next != deck->head)
    {
        Card *aux = next;
        next = next->next;
        free(aux);
    }

    deck->head->next = deck->head;
    deck->head->previous = deck->head;
}

int deckSize(Deck *deck)
{
    Card *next = deck->head->next;
    int size = 0;

    while (next != deck->head)
    {
        size++;
        next = next->next;
    }

    return size;
}

void printDeck(Deck *deck)
{
    Card *previous = deck->head->previous;

    printf("Deck\n");

    while (previous != deck->head)
    {
        printf("%i ", previous->key);
        previous = previous->previous;
    }

    printf("\n");
}

bool insertCard(Deck *deck, Key key, bool isFront)
{
    Card *card = (Card *)malloc(sizeof(Card));
    card->key = key;

    if (isFront)
    {
        card->next = deck->head->next;
        card->next->previous = card;
        card->previous = deck->head;
        deck->head->next = card;
    }
    else
    {
        card->next = deck->head;
        card->previous = deck->head->previous;
        deck->head->previous = card;
        card->previous->next = card;
    }

    return true;
}

bool removeCard(Deck *deck, Key *key, bool isFront)
{
    if (deck->head->next == deck->head)
    {
        return false;
    }

    Card *aux;

    if (isFront)
    {
        aux = deck->head->next;
        deck->head->next = aux->next;
        aux->next->previous = deck->head;
    }
    else
    {
        aux = deck->head->previous;
        deck->head->previous = aux->previous;
        aux->previous->next = deck->head;
    }

    *key = aux->key;

    free(aux);
    return true;
}

int main()
{
    Deck deck;
    startdeck(&deck);

    for (int i = 0; i < MAX; i++)
    {
        insertCard(&deck, i + 1, (bool)(i % 2));
    }

    printDeck(&deck);

    printf("deck size => %i \n", deckSize(&deck));

    for (int i = 0; i < MAX / 2; i++)
    {
        Key key;
        removeCard(&deck, &key, (bool)(i % 2));
        printf("%i ", key);
    }

    printDeck(&deck);

    restartDeck(&deck);

    return 0;
}
