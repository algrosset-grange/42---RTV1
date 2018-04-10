/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:24:48 by agrosset          #+#    #+#             */
/*   Updated: 2017/11/24 12:24:49 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_error_p3(int type_error)
{
	if (type_error == ERROR_BAD_VAR)
		ft_putstr("Variable non acceptable.");
	if (type_error == ERROR_NOT_INT)
		ft_putstr("la valeur saisi n'est pas un int.");
	if (type_error == ERROR_NOT_DOUBLE)
		ft_putstr("la valeur saisi n'est pas un double.");
	if (type_error == ERROR_NOT_UNS_INT)
		ft_putstr("la valeur saisi n'est pas un unsigned int.");
	if (type_error == ERROR_NOT_UNS_DOUBLE)
		ft_putstr("la valeur saisi n'est pas un unsigned double.");
	if (type_error == ERROR_STRUCTURE_END_LINE)
		ft_putstr("fin de ligne inaceptable.");
	if (type_error == ERROR_LIGNE_NO_USE)
		ft_putstr("ligne non utilise.");
}

static void	ft_error_p2(int type_error)
{
	if (type_error == ERROR)
		ft_putstr("inconnu.");
	if (type_error == ERROR_OPEN_FILE)
		ft_putstr("erreur d'ouverture de fichier.");
	if (type_error == ERROR_MALLOC)
		ft_putstr("erreur d'allocation de memoire.");
	if (type_error == ERROR_FIN_STRUCTURE_JSON)
		ft_putstr("structure : sur la fin de fichier.");
	if (type_error == ERROR_STRUCTURE_BRACKET)
		ft_putstr("structure : nombre de crochet.");
	if (type_error == ERROR_STRUCTURE_CURLY_BRACKET)
		ft_putstr("structure : nombre d'accolade.");
	if (type_error == ERROR_STRUCTURE_NB_PAREN)
		ft_putstr("structure : nombre de parenthese.");
	if (type_error == ERROR_ANNONCE)
	{
		ft_putstr("structure : error dans l'annonce ");
		ft_putstr("(mauvaise variable ou structure).");
	}
	if (type_error == ERROR_STRUCTURE_NUMBER)
		ft_putstr("structure précedent une valeur numérique.");
	ft_error_p3(type_error);
}

int			ft_error(int type_error)
{
	ft_putstr("type d'erreur : ");
	ft_error_p2(type_error);
	ft_putstr("\n");
	return (ERROR);
}

int			ft_check_error(t_checkjson *check, int type_error)
{
	char	*nu_line;

	check->error = ERROR;
	ft_putstr("erreur dans le document\nligne : ");
	nu_line = ft_itoa(check->nu_line);
	ft_putstr(nu_line);
	ft_putstr("\n");
	return (ft_error(type_error));
}
