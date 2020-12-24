static char	*include_width(t_parse parsed, char *output)
{
	char	*otp;
	int		i;

	i = -1;
	if (!(otp = malloc(sizeof(char) * (parsed.width + 1))))
		return (0);
	while (++i < parsed.width)
		otp[i] = ' ';
	otp[parsed.width] = '\0';
	i = -1;
	if (parsed.flag.minus)
		otp = ft_strcpy(otp, output, ft_strlen(output));
	else
	{
		if (parsed.flag.zero == 1 && parsed.precision < 0)
			otp = handle_width_with_zero(otp, output, parsed.width);
		else
		{
			while (++i < parsed.width - (int)ft_strlen(output))
				otp[i] = ' ';
			ft_strlcpy(otp + i, output, ft_strlen(output) + 1);
		}
	}
	return (otp);
}

static int	handle_with_flags(t_parse parsed, char *str_nb)
{
	int		len;
	char	*output;
	int		track_free;

	track_free = 0;
	output = NULL;
	len = ft_strlen(str_nb);
	if (parsed.precision > len)
		output = include_prcision(parsed, str_nb, len);
	if (!output)
	{
		output = str_nb;
		track_free = 1;
	}
	if (parsed.width > (int)ft_strlen(output))
		output = include_width(parsed, output);
	len = ft_strlen(output);
	ft_putstr(output);
	if (track_free == 0)
		free(output);
	return (len);
}

char	*handle_width_with_zero(char *otp, char *str_nb, int width)
{
	int		i;
	int		len;

	i = -1;
	if (*str_nb == '-')
	{
		i++;
		otp[i] = ' ';
		++str_nb;
	}
	len = ft_strlen(str_nb);
	while (++i < width - len)
		otp[i] = '0';
	ft_strlcpy(otp + i, str_nb, len + 1);
	return (otp);
}
static int	handle_with_flags(t_parse parsed, char *str_nb)
{
	int		len;
	char	*output;
	int		track_free;

	track_free = 0;
	output = NULL;
	len = ft_strlen(str_nb);
	if (parsed.precision > len)
		output = include_prcision(parsed, str_nb, len);
	else
	{
		output = str_nb;
		track_free = 1;
	}
	if (parsed.width > (int)ft_strlen(output))
	{
		include_width(parsed, output);
		len = parsed.width;
	}
	else
	{
		len = ft_strlen(output);
		ft_putstr(output);
	}
	if (track_free == 0)
		free(output);
	return (len);
}