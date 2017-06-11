/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;
import java.util.Random;




/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
//   public void testManualTest()
//   {
//	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
//	   ResultPair[] testUrls = {new ResultPair("https://www.google.com", true),
//               new ResultPair("http://google.co.uk", true),
//               new ResultPair("http://google.com", true),
//               new ResultPair("google.com", true),
//               new ResultPair("http://www.site.com?action=view", true),
//               new ResultPair("http://999.999.999.999", false),
//               new ResultPair("http://sub.domain.com", true)
//	   };
//	   for (int i = 0; i < testUrls.length; i++) {
//		   String testUrl = testUrls[i].item;
//		   Boolean expectedResult = testUrls[i].valid;
//		   if(urlVal.isValid(testUrl) != expectedResult) {
//			   System.out.println("Test Failure: " + testUrl + " " + "expected to be " + expectedResult);
//		   }
//	   }
//   }
//   
//   
//   public void testYourFirstPartition()
//   {
//	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
//	   ResultPair[] testUrlScheme = {new ResultPair("http://", true),
//               new ResultPair("ftp://", true),
//               new ResultPair("h3t://", true),
//               new ResultPair("3ht://", false),
//               new ResultPair("http:/", false),
//               new ResultPair("http:", false),
//               new ResultPair("http/", false),
//               new ResultPair("://", false),
//               new ResultPair("", true)};
//	   
//	   for (int i = 0; i < testUrlScheme.length; i++) {
//		   String testUrl = testUrlScheme[i].item + "google.com";
//		   Boolean expectedResult = testUrlScheme[i].valid;
//		   if(urlVal.isValid(testUrl) != expectedResult) {
//			   System.out.println("Test Failure: " + testUrl + " " + "expected to be " + expectedResult);
//		   }
//	   }
//   }
//   
//   public void testYourSecondPartition()
//   {
//	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
//	   ResultPair[] testUrlAuthority = {new ResultPair("www.google.com", true),
//               new ResultPair("go.com", true),
//               new ResultPair("go.au", true),
//               new ResultPair("0.0.0.0", true),
//               new ResultPair("255.255.255.255", true),
//               new ResultPair("256.256.256.256", false),
//               new ResultPair("255.com", true),
//               new ResultPair("1.2.3.4.5", false),
//               new ResultPair("1.2.3.4.", false),
//               new ResultPair("1.2.3", false),
//               new ResultPair(".1.2.3.4", false),
//               new ResultPair("go.a", false),
//               new ResultPair("go.a1a", false),
//               new ResultPair("go.cc", true),
//               new ResultPair("go.1aa", false),
//               new ResultPair("aaa.", false),
//               new ResultPair(".aaa", false),
//               new ResultPair("aaa", false),
//               new ResultPair("", false)
//	   };
//	   
//	   for (int i = 0; i < testUrlAuthority.length; i++) {
//		   String testUrl = "http://" + testUrlAuthority[i].item;
//		   Boolean expectedResult = testUrlAuthority[i].valid;
//		   if(urlVal.isValid(testUrl) != expectedResult) {
//			   System.out.println("Test Failure: " + testUrl + " " + "expected to be " + expectedResult);
//		   }
//	   }
//	   
//   }
   
   
   public void testIsValid()
   {
	   Random random = new Random();
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   ResultPair[] testUrlScheme = {new ResultPair("http://", true),
               new ResultPair("ftp://", true),
               new ResultPair("h3t://", true),
               new ResultPair("3ht://", false),
               new ResultPair("http:/", false),
               new ResultPair("http:", false),
               new ResultPair("http/", false),
               new ResultPair("://", false),
               new ResultPair("", true)
        };

		ResultPair[] testUrlAuthority = {new ResultPair("www.google.com", true),
		                  new ResultPair("go.com", true),
		                  new ResultPair("go.au", true),
		                  new ResultPair("0.0.0.0", true),
		                  new ResultPair("255.255.255.255", true),
		                  new ResultPair("256.256.256.256", false),
		                  new ResultPair("255.com", true),
		                  new ResultPair("1.2.3.4.5", false),
		                  new ResultPair("1.2.3.4.", false),
		                  new ResultPair("1.2.3", false),
		                  new ResultPair(".1.2.3.4", false),
		                  new ResultPair("go.a", false),
		                  new ResultPair("go.a1a", false),
		                  new ResultPair("go.cc", true),
		                  new ResultPair("go.1aa", false),
		                  new ResultPair("aaa.", false),
		                  new ResultPair(".aaa", false),
		                  new ResultPair("aaa", false),
		                  new ResultPair("", false)
		};
		ResultPair[] testUrlPort = {new ResultPair(":80", true),
		             new ResultPair(":65535", true),
		             new ResultPair(":0", true),
		             new ResultPair("", true),
		             new ResultPair(":-1", false),
		             new ResultPair(":65636", true),
		             new ResultPair(":65a", false)
		};
		ResultPair[] testPath = {new ResultPair("/test1", true),
		          new ResultPair("/t123", true),
		          new ResultPair("/$23", true),
		          new ResultPair("/..", false),
		          new ResultPair("/../", false),
		          new ResultPair("/test1/", true),
		          new ResultPair("", true),
		          new ResultPair("/test1/file", true),
		          new ResultPair("/..//file", false),
		          new ResultPair("/test1//file", false)
		};
		
		ResultPair[] testUrlQuery = {new ResultPair("?action=view", true),
		              new ResultPair("?action=edit&mode=up", true),
		              new ResultPair("", true)
		};
		
	   for(int i = 0;i<10000;i++)
	   {
		   ResultPair scheme = testUrlScheme[random.nextInt(testUrlScheme.length)];
		   ResultPair authority = testUrlAuthority[random.nextInt(testUrlAuthority.length)];
		   ResultPair port = testUrlPort[random.nextInt(testUrlPort.length)];
		   ResultPair path = testPath[random.nextInt(testPath.length)];
		   ResultPair query = testUrlQuery[random.nextInt(testUrlQuery.length)];
		   Boolean includePort = random.nextBoolean();
		   Boolean includePath = random.nextBoolean();
		   Boolean includeQuery = random.nextBoolean();
		   String testUrl = scheme.item + authority.item;
		   Boolean expectedResult = scheme.valid && authority.valid;
		   if (includePort) {
			   testUrl = testUrl + port.item;
			   expectedResult = expectedResult && port.valid;
		   }
		   if (includePath) {
			   testUrl = testUrl + path.item;
			   expectedResult = expectedResult && path.valid;
		   }
		   if (includeQuery) {
			   testUrl = testUrl + query.item;
			   expectedResult = expectedResult && query.valid;
		   }
		   if(urlVal.isValid(testUrl) != expectedResult) {
			   System.out.println("Test Failure: " + testUrl + " " + "expected to be " + expectedResult);
		   }
		   
	   }
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
