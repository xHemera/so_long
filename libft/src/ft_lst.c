/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarsaul <mgarsaul@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-16 14:18:23 by mgarsaul          #+#    #+#             */
/*   Updated: 2025-01-16 14:18:23 by mgarsaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*c;

	c = malloc(sizeof(*c));
	if (c == NULL)
		return (NULL);
	c->content = content;
	c->next = NULL;
	return (c);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	p = (*lst);
	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*l;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		return ;
	p = *lst;
	l = *lst;
	while (p != NULL)
	{
		l = p->next;
		if (del)
			del(p->content);
		free(p);
		p = l;
	}
	*lst = NULL;
}
