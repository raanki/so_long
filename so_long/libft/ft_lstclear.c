/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:22:55 by ranki             #+#    #+#             */
/*   Updated: 2022/11/12 08:13:01 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (*lst == NULL)
	{	
		lst = 0;
		return ;
	}
	t_list *tmp;
	tmp = *lst;
	ft_lstclear(&(tmp->next), del);
	del((tmp->content));
	free(tmp);
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*before;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		before = tmp;
		tmp = tmp->next;
		del(before->content);
		free(before);
	}
	*lst = 0;
}
