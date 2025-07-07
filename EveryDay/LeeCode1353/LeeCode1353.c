#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Event;

typedef struct {
    Event* events;
    int size;
    int capacity;
} MinHeap;

void swap(Event* a, Event* b) {
    Event temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* heap, int index) {
    while (index > 0 && heap->events[(index - 1) / 2].end > heap->events[index].end) {
        swap(&heap->events[(index - 1) / 2], &heap->events[index]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(MinHeap* heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < heap->size && heap->events[left].end < heap->events[smallest].end) {
        smallest = left;
    }
    if (right < heap->size && heap->events[right].end < heap->events[smallest].end) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap->events[index], &heap->events[smallest]);
        heapifyDown(heap, smallest);
    }
}

void push(MinHeap* heap, Event event) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->events = realloc(heap->events, heap->capacity * sizeof(Event));
    }
    heap->events[heap->size++] = event;
    heapifyUp(heap, heap->size - 1);
}

Event pop(MinHeap* heap) {
    Event event = heap->events[0];
    heap->events[0] = heap->events[--heap->size];
    heapifyDown(heap, 0);
    return event;
}

int isEmpty(MinHeap* heap) {
    return heap->size == 0;
}

void freeHeap(MinHeap* heap) {
    free(heap->events);
    free(heap);
}

int compare(const void* a, const void* b) {
    Event* eventA = (Event*)a;
    Event* eventB = (Event*)b;
    if (eventA->start != eventB->start) {
        return eventA->start - eventB->start;
    } else {
        return eventA->end - eventB->end;
    }
}

int maxEvents(int** events, int eventsSize, int* eventsColSize) {
    Event* eventList = malloc(eventsSize * sizeof(Event));
    for (int i = 0; i < eventsSize; i++) {
        eventList[i].start = events[i][0];
        eventList[i].end = events[i][1];
    }

    qsort(eventList, eventsSize, sizeof(Event), compare);

    MinHeap* heap = malloc(sizeof(MinHeap));
    heap->events = malloc(eventsSize * sizeof(Event));
    heap->size = 0;
    heap->capacity = eventsSize;

    int day = 1;
    int eventIndex = 0;
    int attended = 0;

    while (eventIndex < eventsSize || !isEmpty(heap)) {
        // 将当天开始的会议加入堆
        while (eventIndex < eventsSize && eventList[eventIndex].start <= day) {
            push(heap, eventList[eventIndex++]);
        }

        // 移除已经结束的会议
        while (!isEmpty(heap) && heap->events[0].end < day) {
            pop(heap);
        }

        // 如果堆不为空，参加结束时间最早的会议
        if (!isEmpty(heap)) {
            pop(heap);
            attended++;
        }

        day++;
    }

    free(eventList);
    freeHeap(heap);

    return attended;
}

int main() {
    int events1[3][2] = {{1, 2}, {2, 3}, {3, 4}};
    int* events[] = {events1[0], events1[1], events1[2]};
    int eventsColSize[] = {2, 2, 2};
    int eventsSize = 3;
    printf("%d\n", maxEvents(events, eventsSize, eventsColSize)); // 输出 3

    int events2[4][2] = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};
    int* events3[] = {events2[0], events2[1], events2[2], events2[3]};
    int eventsColSize2[] = {2, 2, 2, 2};
    int eventsSize2 = 4;
    printf("%d\n", maxEvents(events3, eventsSize2, eventsColSize2)); // 输出 4

    return 0;
}