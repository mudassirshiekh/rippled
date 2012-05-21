#ifndef __CONFIG__
#define __CONFIG__

#include "types.h"
#include "SerializedTypes.h"

#include <string>

#define SYSTEM_NAME					"newcoin"
#define VALIDATORS_SITE				"redstem.com"
#define SYSTEM_CURRENCY_CODE		"XNS"
#define SYSTEM_CURRENCY_PRECISION	6

#define VALIDATORS_FILE_NAME		"validators.txt"
const int SYSTEM_PEER_PORT = 6561;

// Allow anonymous DH.
#define DEFAULT_PEER_SSL_CIPHER_LIST	"ALL:!LOW:!EXP:!MD5:@STRENGTH"

// 1 hour.
#define DEFAULT_PEER_SCAN_INTERVAL_MIN	(60*60)

// Maximum number of peers to try to connect to as client at once.
#define DEFAULT_PEER_START_MAX			5

// Might connect with fewer for testing.
#define	DEFAULT_PEER_CONNECT_LOW_WATER	4

class Config
{
public:
	// Core software parameters
	int			VERSION;
	std::string	VERSION_STR;

	// Network parameters
	int		NETWORK_START_TIME;		// The Unix time we start ledger 0
	int		TRANSACTION_FEE_BASE;
	int		LEDGER_SECONDS;
	int		LEDGER_PROPOSAL_DELAY_SECONDS;
	int		LEDGER_AVALANCHE_SECONDS;

	// Note: The following parameters do not relate to the UNL or trust at all
	int		NETWORK_QUORUM;		// Minimum number of nodes to consider the network present
	int		VALIDATION_QUORUM;		// Minimum validations to consider ledger authoritative

	// Peer networking parameters
	std::string PEER_IP;
	int		PEER_PORT;
	int		NUMBER_CONNECTIONS;
	std::string PEER_SSL_CIPHER_LIST;
	int		PEER_SCAN_INTERVAL_MIN;
	int		PEER_START_MAX;
	int		PEER_CONNECT_LOW_WATER;

//	bool	    NODE_INBOUND;		// We accept inbound connections
//	bool	    NODE_DATABASE;		// We offer historical data services
//	bool	    NODE_PUBLIC;		// We do not attempt to hide our identity
//	bool	    NODE_DUMB;			// We are a 'dumb' client
//	bool	    NODE_SMART;			// We offer services to 'dumb' clients

	// RPC parameters
	std::string	RPC_IP;
	int			RPC_PORT;
	std::string	RPC_USER;
	std::string	RPC_PASSWORD;

	// Validation
	std::string	VALIDATION_PASSWORD;
	std::string	VALIDATION_KEY;

	// Fees
	uint64		FEE_CREATE;			// Fee to create an account
	uint64		FEE_DEFAULT;		// Default fee.

	// configuration parameters
	std::string DATA_DIR;

	Config();

	void load();
};

extern Config theConfig;
#endif
