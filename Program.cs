using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections;
using System.IO;
using System.Linq;

namespace JsonManager
{
    public class Program
    {
        public static string name = "Alex";
        public static int lvl = 25;
        public static int gold = 23498;
        static string JSON;
        
        static void Main(string[] args)
        {

        }

        public static void WriteJson()
        {
            Player player = new Player()
            {
                IGN = name,
                Level = lvl,
                Gold = gold
            };

            JSON = JsonConvert.SerializeObject(player);
            File.WriteAllText(@"playerData.json", JSON);
        }

        public static void ReadJson()
        {
            JSON = string.Empty;
            JSON = File.ReadAllText(@"playerData.json");
            //            Player resultPlayer = JsonConvert.DeserializeObject<Player>(JSON);
            //            Console.WriteLine(resultPlayer.ToString());

            var dictionary = JsonConvert.DeserializeObject<IDictionary>(JSON);
            foreach (DictionaryEntry element in dictionary)
            {
                Console.WriteLine(element.Key + ": " + element.Value);
            }
        }
    }
}
