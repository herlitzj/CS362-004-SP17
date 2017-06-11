import junit.framework.TestCase;

public class ManualTest extends TestCase {
	public static void main(String[] argv) {
		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	    assertTrue(urlVal.isValid("go.com"));
	}
}