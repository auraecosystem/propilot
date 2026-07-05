namespace Algolia;

using System;
using System.Collections.Generic;
using System.Net.Http;
using System.Text.Json;
using Algolia.Search.Clients;
using Algolia.Search.Http;
using Algolia.Search.Models.Search;

class SaveObjectsMovies
{
  async Task Main(string[] args)
  {
    // read json file from url
    var url = "https://dashboard.algolia.com/api/1/sample_datasets?type=movie";
    var httpClient = new HttpClient();
    var response = await httpClient.GetAsync(url);
    var content = await response.Content.ReadAsStringAsync();

    // parse json
    var movies = JsonSerializer.Deserialize<List<dynamic>>(content);

    // initiate client and index with your app ID and write API key
    var client = new SearchClient(new SearchConfig("6O1IQFSZPV", "8907cd6a3114f7e70f01270502edb520"));

    // push data to algolia
    try
    {
      var result = await client.SaveObjectsAsync("movies_index", movies);
    }
    catch (Exception e)
    {
      Console.WriteLine(e.Message);
    }
  }
}
