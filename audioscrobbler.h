#ifndef _AUDIOSCROBBLER_H
#define _AUDIOSCROBBLER_H


class CAudioScrobbler
{
	public:
		CAudioScrobbler();
		void Handshake();
		const std::string CreateScrobbleMessage(const int index, const centry_t* entry);
		const bool Scrobble(const centry_t* entry);
		void ReportResponse(const char* buf, const size_t size);
		const bool SendNowPlaying(const mpd_Song* song);
		void Failure();
	private:
		void OpenURL(const std::string& url, const char* postfields, const char* errbuf);
		const bool CheckFailure(const std::string& response);

		CURL* _handle;

		std::string _password;
		std::string _response;

		std::string _sessionid;

		bool _authed;
		int _failcount;
};

extern CAudioScrobbler* AudioScrobbler;

#endif
