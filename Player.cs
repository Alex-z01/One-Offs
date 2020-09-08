using Newtonsoft.Json;
using System;

namespace JsonManager
{
    class Player
    {
        static void Main(string[] args)
        {

        }

        [JsonProperty]
        public string IGN { get; set; }

        [JsonProperty]
        public int Gold { get; set; }

        [JsonProperty]
        public int Level { get; set; }

        public override string ToString()
        {
            return string.Format("Player Data:\n\tIGN: {0}, \n\tGold: {1}, \n\tLevel: {2}", IGN, Gold, Level);
        }
    }
}

