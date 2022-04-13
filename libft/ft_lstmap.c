/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktanemur <ktanemur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:14:14 by ktanemur          #+#    #+#             */
/*   Updated: 2022/04/13 10:14:14 by ktanemur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*out;

	out = NULL;
	while (lst != NULL)
	{
		newlst = ft_lstnew(f(lst->content));
		if (!newlst)
		{
			ft_lstclear(&out, del);
			return (NULL);
		}
		ft_lstadd_back(&out, newlst);
		lst = lst -> next;
	}
	return (out);
}
