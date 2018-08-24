double	eqpt_derivative_old(int counter, double *phs, double *volumes)
{
	double	y1 = 0.0;
	double	y2 = 0.0;
	double	derivative_2 = 0.0;

	if (counter <= 1) {
		return ((phs[2] - phs[0]) / (volumes[2] - volumes[0]));
	}
	y1 = eqpt_derivative_old((counter - 1), &phs[2], &volumes[2]);
	y2 = eqpt_derivative_old((counter - 1), &phs[0], &volumes[0]);
	derivative_2 = ((y2 - y1) / (volumes[3] - volumes[1]));
	return (derivative_2);
}
