double saldo;



double neem_op(double bedrag) {
	if (saldo >= bedrag) {
		saldo -= bedrag;
		return bedrag;
	}
	else if (saldo < bedrag){
		double werkelijkopgenomen = saldo;
		saldo = 0;
		return werkelijkopgenomen;
	}
}
