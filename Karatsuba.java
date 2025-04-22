import java.util.*;
public class Karatsuba 
{
	public static void main(String[] args)
	{
		System.out.println(multiply("1010", "1100"));
	}
	public static long multiply(String X, String Y)
	{
		int n = Math.max(X.length(), Y.length());
		X = String.format("%" + n + "s", X) .replace(' ', '0');
		Y = String.format("%" + n + "s", Y) .replace(' ', '0');
		if (n == 0)
			return 0;
		if (n == 1)
			return Integer.parseInt(X)
				* Integer.parseInt(Y);
		int fh = n / 2;
		int sh = n - fh;
		String Xl = X.substring(0, fh);
		String Xr = X.substring(fh);
		String Yl = Y.substring(0, fh);
		String Yr = Y.substring(fh);
		long P1 = multiply(Xl, Yl);
		long P2 = multiply(Xr, Yr);
		long P3 = multiply(Integer.toBinaryString(Integer.parseInt(Xl, 2) + Integer.parseInt(Xr, 2)),
						Integer.toBinaryString( Integer.parseInt(Yl, 2) + Integer.parseInt(Yr, 2)));
		return P1 * (1L << (2 * sh))
			+ (P3 - P1 - P2) * (1L << sh) + P2;
	}
}