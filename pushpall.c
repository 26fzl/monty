#include "monty.h"

/**
 * f_pall - print the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
 */

void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

#include "monty.h"

/**
 * f_push - adding node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void f_push(stack_t **head, unsigned int counter)
{
	int x, z = 0, flags = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			z++;
		for (; bus.arg[z] != '\0'; z++)
		{
			if (bus.arg[z] > 57 || bus.arg[z] < 48)
				flags = 1; }
		if (flags == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	x = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, x);
	else
		addqueue(head, x);
}
