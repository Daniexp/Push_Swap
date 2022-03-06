#include "../incl/push_swap.h"

/*
	crearnos una lista a partir del int como argumento
	Tenemos que comprobar si el número es repetido
		es decir recorrer la lista buscando el número a añadir
		si no esta no es repetido
	si es repetido err_msg();
	si no lo es lo añadimos al final¿?
*/

void	sv_lst_nrpt(t_list **lst, int num)
{
	t_list	**aux;

	aux = lst;
	while (*aux)
	{
		if (*(int*)(*aux)->content == num)
			err_msg();
		(*aux) = (*aux)->next;
	}
	if (!*lst)
		*lst = ft_lstnew((num));
	else
		ft_lstadd_back(lst, ft_lstnew(num));
}
