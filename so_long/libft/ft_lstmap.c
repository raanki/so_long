/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:54:04 by ranki             #+#    #+#             */
/*   Updated: 2022/11/12 11:33:38 by ranki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*root;

	if (lst == NULL)
		return (NULL);
	tmp = lst;
	root = ft_lstnew(f(tmp->content));
	tmp = tmp->next;
	while (tmp != NULL)
	{
		ft_lstadd_back(&root, ft_lstnew(f(tmp->content)));
		if (ft_lstlast(root) == NULL)
		{
			ft_lstclear(&root, del);
			free(root);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (root);
}
